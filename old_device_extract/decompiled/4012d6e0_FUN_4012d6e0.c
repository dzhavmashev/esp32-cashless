// Function : FUN_4012d6e0
// Address  : 0x4012d6e0
// Size     : 32 bytes


bool FUN_4012d6e0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_40173a8c();
  iVar2 = *piVar1;
  piVar1 = (int *)FUN_40173a8c();
  *piVar1 = iVar2;
  memw();
  return iVar2 == 0xb;
}

