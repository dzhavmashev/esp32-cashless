// Function : FUN_400f6c4c
// Address  : 0x400f6c4c
// Size     : 409 bytes


uint FUN_400f6c4c(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  iVar3 = param_1 * 4;
  piVar4 = (int *)(iVar3 + 0x3ffc5588);
  memw();
  (*(code *)&SUB_40090010)(*(undefined4 *)(*piVar4 + 0xe4),0xffffffff);
  iVar6 = *piVar4;
  *(undefined1 *)(iVar6 + 0x10) = 0;
  memw();
  uVar1 = param_3;
  if (*(int *)(iVar6 + 0xb4) < 1) {
    while (uVar1 != 0) {
      iVar6 = (*(code *)&SUB_40090010)(*(undefined4 *)(*piVar4 + 0xe8),0xffffffff);
      if (iVar6 == 1) {
        memw();
        uVar2 = FUN_400f5d20(param_1,param_2,uVar1);
        if (uVar2 < uVar1) {
          *(undefined1 *)(*piVar4 + 0xb8) = 1;
          memw();
          memw();
          FUN_400f6b80(param_1,1,10);
        }
        param_2 = param_2 + uVar2;
        uVar1 = uVar1 - uVar2;
      }
    }
    if (param_4 != 0) {
      piVar4 = (int *)(param_1 * 0x10 + 0x3ffbdc78);
      iVar6 = param_1 * 0x10 + 0x3ffbdc7c;
      memw();
      *(undefined4 *)(*piVar4 + 0x10) = 0x1000;
      memw();
      (*(code *)&SUB_40092a98)(iVar6,0xffffffff);
      FUN_400fe380(piVar4,param_5);
      memw();
      memw();
      *(uint *)(*piVar4 + 0xc) = *(uint *)(*piVar4 + 0xc) | 0x1000;
      memw();
      (*(code *)&SUB_40092bec)(iVar6);
      (*(code *)&SUB_40090010)(*(undefined4 *)(*(int *)(iVar3 + 0x3ffc5588) + 0xf0),0xffffffff);
    }
    (*(code *)&SUB_4008fab8)(*(undefined4 *)(*(int *)(iVar3 + 0x3ffc5588) + 0xe8),0,0);
  }
  else {
    memw();
    uVar1 = (*(code *)&SUB_4008eebc)(*(undefined4 *)(iVar6 + 0xdc));
    uStack_2c = 0;
    if (param_4 != 0) {
      uStack_2c = 6;
    }
    memw();
    uStack_28 = param_5;
    uStack_24 = param_3;
    (*(code *)&SUB_4008eb98)(*(undefined4 *)(*piVar4 + 0xdc),&uStack_2c,0xc,0xffffffff);
    iVar6 = 0;
    uVar1 = uVar1 >> 1;
    uVar2 = param_3;
    while (uVar2 != 0) {
      iVar5 = (uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2;
      iVar7 = param_2 + iVar6;
      iVar6 = iVar5 + iVar6;
      memw();
      (*(code *)&SUB_4008eb98)(*(undefined4 *)(*piVar4 + 0xdc),iVar7,iVar5,0xffffffff);
      uVar2 = uVar2 - iVar5;
      memw();
      FUN_400f6b80(param_1,1,10);
    }
  }
  (*(code *)&SUB_4008fab8)(*(undefined4 *)(*(int *)(iVar3 + 0x3ffc5588) + 0xe4),0,0);
  return param_3;
}

