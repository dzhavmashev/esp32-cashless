// Function : FUN_400eaf18
// Address  : 0x400eaf18
// Size     : 172 bytes


void FUN_400eaf18(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int aiStack_28 [10];
  
  iVar4 = param_1 + 0x68c;
  iVar2 = FUN_40184578(iVar4);
  aiStack_28[0] = *(int *)(param_1 + 0x678);
  uVar1 = *(ushort *)(iVar2 + 0x88);
  aiStack_28[1] = 0;
  while( true ) {
    if (aiStack_28[0] == 0) {
      return;
    }
    iVar2 = FUN_401844a8(aiStack_28[0] + 4);
    if ((iVar2 == 0x80) && (uVar3 = FUN_401844a0(aiStack_28[0] + 4), uVar1 == uVar3)) break;
    (*(code *)&LAB_40184487_1)(aiStack_28);
  }
  FUN_400dad2c(param_1 + 0x678,aiStack_28);
  if (*(int *)(param_1 + 0x34) == 0) {
    return;
  }
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  iVar2 = FUN_40184578(iVar4);
  uVar5 = *(undefined4 *)(iVar2 + 0x8c);
  iVar2 = FUN_40184578(iVar4);
  uStack_2c = *(undefined4 *)(iVar2 + 0x98);
  uStack_32 = uVar1;
  uStack_30 = uVar5;
  if (*(int *)(param_1 + 0x34) == 0) {
    FUN_40170584();
  }
  (**(code **)(param_1 + 0x38))(param_1 + 0x2c,&uStack_32,&uStack_30,&uStack_2c);
  func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
  return;
}

