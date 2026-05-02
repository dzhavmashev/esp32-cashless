// Function : FUN_401021e4
// Address  : 0x401021e4
// Size     : 52 bytes


int FUN_401021e4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)&SUB_40094d60)(0x22);
  if (iVar1 != 0) {
    FUN_4013ce78();
    iVar2 = FUN_4013cea0(iVar1,param_1,param_2 << 3);
    if (iVar2 < 0) {
      FUN_4013ce8c(iVar1);
      (*(code *)&SUB_40094d80)(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

