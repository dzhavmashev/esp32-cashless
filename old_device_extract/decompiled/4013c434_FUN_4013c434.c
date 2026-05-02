// Function : FUN_4013c434
// Address  : 0x4013c434
// Size     : 155 bytes


int FUN_4013c434(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 4);
  if ((param_4 != 1) || (iVar1 = -0x4080, *(int *)(param_1 + 0xa4) == 0)) {
    memw();
    iVar2 = FUN_4013ae30(1,uVar5);
    iVar1 = -0x10;
    if (iVar2 != 0) {
      iVar3 = FUN_4013ae30(1,uVar5);
      iVar1 = -0x10;
      if ((iVar3 != 0) && (iVar1 = FUN_4013af44(param_5,param_6,param_7,uVar5,iVar3), iVar1 == 0)) {
        if (param_4 == 0) {
          iVar1 = FUN_4013b510(param_1,param_8,iVar2);
        }
        else {
          iVar1 = FUN_4013b574(param_1,param_2,param_3,param_8,iVar2);
        }
        if ((iVar1 == 0) && (iVar4 = FUN_401862dc(iVar2,iVar3,uVar5), iVar1 = 0, iVar4 != 0)) {
          iVar1 = -0x4380;
        }
      }
      FUN_4013ae54(iVar2,uVar5);
      FUN_4013ae44(iVar2);
      if (iVar3 != 0) {
        FUN_4013ae54(iVar3,uVar5);
        FUN_4013ae44(iVar3);
      }
    }
  }
  return iVar1;
}

