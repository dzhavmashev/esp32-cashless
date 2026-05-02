// Function : FUN_40139b04
// Address  : 0x40139b04
// Size     : 61 bytes


undefined4 FUN_40139b04(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((*param_2 == 0) || (uVar4 = 0, param_1 != 0)) {
    iVar1 = FUN_40138f28(param_1);
    if ((iVar1 == 0) || ((iVar3 = *param_2, iVar3 != 0 && (iVar2 = FUN_401864c4(), iVar3 != iVar2)))
       ) {
      uVar4 = 0xffffffff;
    }
    else {
      iVar1 = FUN_401864c4(iVar1);
      *param_2 = iVar1;
      uVar4 = 0;
      memw();
    }
  }
  return uVar4;
}

