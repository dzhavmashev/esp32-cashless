// Function : FUN_4013c0fc
// Address  : 0x4013c0fc
// Size     : 198 bytes


int FUN_4013c0fc(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 != 1) || (iVar3 = -0x4080, *(int *)(param_1 + 0xa4) == 0)) {
    memw();
    iVar3 = FUN_4013af44(param_5,param_6,param_7,*(undefined4 *)(param_1 + 4),param_8);
    if (iVar3 == 0) {
      if (param_4 == 0) {
        iVar3 = FUN_4013b510(param_1,param_8,param_8);
      }
      else {
        iVar1 = FUN_4013ae30(1,*(undefined4 *)(param_1 + 4));
        iVar3 = -0x10;
        if (iVar1 != 0) {
          iVar2 = FUN_4013ae30(1,*(undefined4 *)(param_1 + 4));
          if (iVar2 == 0) {
            FUN_4013ae44(iVar1);
            iVar3 = -0x10;
          }
          else {
            iVar3 = FUN_4013b574(param_1,param_2,param_3,param_8,iVar1);
            if ((iVar3 == 0) && (iVar3 = FUN_4013b510(param_1,iVar1,iVar2), iVar3 == 0)) {
              iVar3 = FUN_401862dc(iVar2,param_8,*(undefined4 *)(param_1 + 4));
              if (iVar3 == 0) {
                (*(code *)&SUB_4008b3d0)(param_8,iVar1,*(undefined4 *)(param_1 + 4));
                iVar3 = 0;
              }
              else {
                iVar3 = -0x4300;
              }
            }
            FUN_4013ae54(iVar1,*(undefined4 *)(param_1 + 4));
            FUN_4013ae54(iVar2,*(undefined4 *)(param_1 + 4));
            FUN_4013ae44(iVar1);
            FUN_4013ae44(iVar2);
            if (iVar3 != 0) {
              (*(code *)&SUB_4008b530)(param_8,0x21,*(undefined4 *)(param_1 + 4));
            }
          }
        }
      }
    }
  }
  return iVar3;
}

