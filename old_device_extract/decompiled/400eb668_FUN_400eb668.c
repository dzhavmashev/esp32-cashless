// Function : FUN_400eb668
// Address  : 0x400eb668
// Size     : 98 bytes


void FUN_400eb668(int param_1)

{
  int iVar1;
  uint uVar2;
  ushort uStack_2a;
  int aiStack_28 [10];
  
  iVar1 = FUN_40184578(param_1 + 0x68c);
  uStack_2a = *(ushort *)(iVar1 + 0x88);
  aiStack_28[0] = *(int *)(param_1 + 0x678);
  aiStack_28[1] = 0;
  while( true ) {
    if (aiStack_28[0] == 0) {
      return;
    }
    iVar1 = FUN_401844a8(aiStack_28[0] + 4);
    if (iVar1 == 0x30) break;
    (*(code *)&LAB_40184487_1)(aiStack_28);
  }
  uVar2 = FUN_401844a0(aiStack_28[0] + 4);
  if (uStack_2a != uVar2) {
    return;
  }
  FUN_400eb4ac(param_1,&DAT_3f40993e,&uStack_2a);
  FUN_400dad2c(param_1 + 0x678,aiStack_28);
  return;
}

