// Function : FUN_40127b44
// Address  : 0x40127b44
// Size     : 282 bytes


undefined4
FUN_40127b44(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x48);
  if (iVar3 != 0) {
    for (; param_2 != (undefined4 *)0x0; param_2 = (undefined4 *)*param_2) {
      if (param_2[1] == *(int *)(param_1 + 0x3c)) {
        memw();
        iVar1 = (*(code *)&SUB_4008b33c)(param_3,param_4,6);
        *(byte *)(iVar3 + 0x6c) =
             *(byte *)(iVar3 + 0x6c) & 0xfe | (byte)((uint)((iVar1 >> 0x1f) - iVar1) >> 0x1f);
        memw();
        memw();
        FUN_4010531c(*(undefined4 *)(iVar3 + 100));
        *(undefined4 *)(*(int *)(param_1 + 0x48) + 100) = 0;
        if (param_5 != 0) {
          memw();
          iVar3 = FUN_4018506c(param_5);
          iVar1 = FUN_401052d0(iVar3 << 1);
          iVar4 = 0;
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          for (; iVar4 < iVar3; iVar4 = iVar4 + 1) {
            memw();
            FUN_40125ffc(iVar1,*(undefined2 *)(param_5 + iVar4 * 4));
          }
          *(int *)(*(int *)(param_1 + 0x48) + 100) = iVar1;
        }
        if (param_2[2] != 0) {
          FUN_40128d84(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x34),1);
          iVar3 = *(int *)(param_1 + 0x48);
          uVar2 = FUN_40127510(param_2,param_3,param_4);
          *(undefined4 *)(iVar3 + 0x34) = uVar2;
          if (*(int *)(*(int *)(param_1 + 0x48) + 0x34) == 0) {
            memw();
            return 0xffffffff;
          }
        }
        if (param_2[4] != 0) {
          FUN_40128a7c(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x38),1);
          iVar1 = *(int *)(param_1 + 0x48);
          uVar2 = FUN_4012768c(param_2,param_3,param_4);
          iVar3 = *(int *)(param_1 + 0x48);
          *(undefined4 *)(iVar1 + 0x38) = uVar2;
          if (*(int *)(iVar3 + 0x38) == 0) {
            memw();
            return 0xffffffff;
          }
        }
        *(byte *)(param_1 + 0x50) = *(byte *)(param_1 + 0x50) | 1;
        memw();
        memw();
        uVar2 = FUN_40127038(param_1);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

