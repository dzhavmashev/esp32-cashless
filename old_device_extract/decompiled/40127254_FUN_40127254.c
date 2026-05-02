// Function : FUN_40127254
// Address  : 0x40127254
// Size     : 188 bytes


undefined4 FUN_40127254(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_40127228(param_1);
  iVar1 = (*(code *)&SUB_40094dd8)(1,0x70);
  *(int *)(param_1 + 0x48) = iVar1;
  if (iVar1 != 0) {
    iVar3 = FUN_40128d10(param_2);
    *(int *)(iVar1 + 0x40) = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x3c) = param_2;
      memw();
      uVar2 = FUN_40128d5c();
      *(undefined4 *)(iVar1 + 0x44) = uVar2;
      memw();
      uVar2 = FUN_401857ec(*(undefined4 *)(iVar1 + 0x40));
      *(undefined4 *)(iVar1 + 0x4c) = uVar2;
      memw();
      uVar2 = FUN_40128d68(*(undefined4 *)(iVar1 + 0x40));
      *(undefined4 *)(iVar1 + 0x60) = uVar2;
      memw();
      uVar4 = FUN_401857f4(*(undefined4 *)(iVar1 + 0x40));
      uVar2 = 0;
      *(undefined4 *)(iVar1 + 0x50) = uVar4;
      goto LAB_401272b7;
    }
    iVar3 = FUN_401289f0(param_2);
    *(int *)(iVar1 + 0x48) = iVar3;
    if (iVar3 != 0) {
      iVar5 = *(int *)(iVar3 + 0x10);
      *(undefined4 *)(param_1 + 0x3c) = param_2;
      *(int *)(iVar1 + 0x44) = iVar5;
      if (iVar5 < 0x201) {
        iVar3 = FUN_40128a30(*(undefined4 *)(iVar3 + 0xc));
        *(int *)(iVar1 + 0x54) = iVar3;
        if (iVar3 != 0) {
          uVar4 = *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x18);
          *(int *)(iVar1 + 0x4c) = iVar3;
          uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x14);
          *(undefined4 *)(iVar1 + 0x60) = uVar4;
          memw();
          iVar3 = FUN_40128a30(uVar2);
          *(int *)(iVar1 + 0x58) = iVar3;
          if (iVar3 != 0) {
            *(int *)(iVar1 + 0x50) = iVar3;
            memw();
            uVar2 = 0;
            goto LAB_401272b7;
          }
        }
      }
      memw();
      FUN_40127228(param_1);
    }
  }
  uVar2 = 0xffffffff;
  memw();
LAB_401272b7:
  memw();
  return uVar2;
}

