// Function : FUN_40155000
// Address  : 0x40155000
// Size     : 39 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_40155000(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_40154dd4();
  cVar1 = '\x0e';
  if (*(int *)(_DAT_3ffbfc54 + 0x490) != 0) {
    cVar1 = *(char *)(iVar2 + 3) + *(char *)(iVar2 + 4) + -1;
  }
  return cVar1;
}

