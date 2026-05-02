// Function : FUN_40128dd4
// Address  : 0x40128dd4
// Size     : 91 bytes


int FUN_40128dd4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar1 = FUN_401317d8(param_1 + 4);
    iVar2 = (*(code *)&SUB_40094dd8)(1,0x24);
    if (iVar2 != 0) {
      FUN_4013562c();
      iVar3 = FUN_4013183c(iVar2,param_2,iVar1);
      if (((iVar3 == 0) && (iVar1 = FUN_4013183c(iVar2 + 0xc,param_2 + iVar1,iVar1), iVar1 == 0)) &&
         (iVar1 = FUN_40131700(iVar2 + 0x18,1), iVar1 == 0)) {
        return iVar2;
      }
      FUN_401356a8(iVar2);
      (*(code *)&SUB_40094d80)(iVar2);
    }
  }
  return 0;
}

