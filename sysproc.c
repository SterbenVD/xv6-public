#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_date(void){
  struct rtcdate* p;
  if(argptr(0, (void*)&p, sizeof(*p)))
    return -1;
  // cprintf("%d:%p",sizeof(*p),p);
  cmostime(p);
  return 0;
}

int sys_pgtPrint(void)
{
  struct proc *curproc = myproc();
  pde_t *pagedir = curproc->pgdir;
  for(uint i=0;i<NPDENTRIES;i++){
    if(pagedir[i] && PTE_P){
      pte_t *pagetable = (pte_t*)P2V(PTE_ADDR(pagedir[i]));
      for (int j = 0; j < NPTENTRIES; j++) {
        if (pagetable[j] & PTE_P && (pagetable[j] & PTE_U)) {
          cprintf("Page Entry %d: Virtual Address: 0x%p, Physical Address: 0x%p\n", j, PGADDR(i,j,0),pagetable[j]);
        }
      }
    }
  }
  return 0;
}