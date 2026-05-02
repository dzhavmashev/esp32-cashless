// Function : FUN_400e0bf4
// Address  : 0x400e0bf4
// Size     : 193 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e0bf4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e03e0(*(undefined4 *)(param_1 + 0x14),param_1 + 0x10,param_2);
  if ((iVar1 == param_1 + 0x10) || (iVar2 = FUN_400f1218(param_2,iVar1 + 0x10), iVar2 != 0)) {
    uStack_40 = param_2;
    iVar1 = FUN_400e0b40(param_1 + 0xc,iVar1,"artTask",&uStack_40,&uStack_41);
  }
  uStack_2c = 0;
  if (*(code **)(param_3 + 8) != (code *)0x0) {
    (**(code **)(param_3 + 8))(&uStack_34,param_3,2);
    uStack_28 = *(undefined4 *)(param_3 + 0xc);
    uStack_2c = *(undefined4 *)(param_3 + 8);
  }
  uVar5 = *(undefined4 *)(iVar1 + 0x24);
  uStack_38 = uStack_30;
  *(undefined4 *)(iVar1 + 0x24) = uStack_30;
  uVar3 = *(undefined4 *)(iVar1 + 0x28);
  *(undefined4 *)(iVar1 + 0x28) = uStack_2c;
  uVar6 = *(undefined4 *)(iVar1 + 0x20);
  uVar4 = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined4 *)(iVar1 + 0x20) = uStack_34;
  *(undefined4 *)(iVar1 + 0x2c) = uStack_28;
  uStack_3c = uStack_34;
  uStack_34 = uVar6;
  uStack_30 = uVar5;
  uStack_2c = uVar3;
  uStack_28 = uVar4;
  (*(code *)&LAB_40183a17_1)(&uStack_34);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    (*(code *)&LAB_40183a17_1)(&uStack_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

