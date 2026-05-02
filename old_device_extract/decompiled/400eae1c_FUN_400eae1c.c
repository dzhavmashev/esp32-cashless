// Function : FUN_400eae1c
// Address  : 0x400eae1c
// Size     : 120 bytes


void FUN_400eae1c(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int aiStack_28 [10];
  
  iVar2 = FUN_40184578(param_1 + 0x68c);
  aiStack_28[0] = *(int *)(param_1 + 0x678);
  uVar1 = *(ushort *)(iVar2 + 0x88);
  aiStack_28[1] = 0;
  while( true ) {
    if (aiStack_28[0] == 0) {
      return;
    }
    iVar2 = FUN_401844a8(aiStack_28[0] + 4);
    if (iVar2 == 0x30) break;
    (*(code *)&LAB_40184487_1)(aiStack_28);
  }
  uVar3 = FUN_401844a0(aiStack_28[0] + 4);
  if (uVar1 != uVar3) {
    return;
  }
  FUN_400dad2c(param_1 + 0x678,aiStack_28);
  if (*(int *)(param_1 + 100) == 0) {
    return;
  }
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  FUN_400eadb0(param_1 + 0x5c,(uint)uVar1);
  func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
  return;
}

