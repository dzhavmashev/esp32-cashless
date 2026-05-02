// Function : FUN_400f8b2c
// Address  : 0x400f8b2c
// Size     : 34 bytes


int FUN_400f8b2c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)&SUB_40094d60)(0x70);
  if (iVar1 != 0) {
    FUN_4013f784();
    iVar2 = FUN_4013f7ec(iVar1,0);
    if (iVar2 == 0) {
      return iVar1;
    }
  }
  return 0;
}

