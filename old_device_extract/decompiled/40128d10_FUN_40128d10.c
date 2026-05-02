// Function : FUN_40128d10
// Address  : 0x40128d10
// Size     : 50 bytes


int FUN_40128d10(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == 0x13) && (iVar1 = (*(code *)&SUB_40094dd8)(1,0x7c), iVar1 != 0)) {
    FUN_40135644();
    iVar2 = FUN_401378f0(iVar1,3);
    if (iVar2 == 0) {
      return iVar1;
    }
    FUN_40128cf8(iVar1);
  }
  return 0;
}

