// Function : FUN_4012f3a4
// Address  : 0x4012f3a4
// Size     : 126 bytes


undefined4 FUN_4012f3a4(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  iVar3 = *param_1;
  iVar1 = FUN_40185bd4(iVar3);
  if (iVar1 == 0) {
    return 0xffff8a00;
  }
  puVar4 = (undefined1 *)*param_2;
  if (param_3 - (int)puVar4 < 2) {
    return 0xffff8400;
  }
  puVar5 = puVar4 + 2;
  uVar2 = (uint)CONCAT11(*puVar4,puVar4[1]);
  *param_2 = (int)puVar5;
  if (uVar2 == 0) {
    return 0xffff8400;
  }
  if (param_3 - (int)puVar5 < (int)uVar2) {
    return 0xffff8400;
  }
  if (*(code **)(iVar3 + 0x70) == (code *)0x0) {
    if (*(uint *)(iVar3 + 0xd8) != uVar2) goto LAB_4012f3f4;
    iVar1 = FUN_401862dc(*(undefined4 *)(iVar3 + 0xd4),puVar5,uVar2);
  }
  else {
    memw();
    iVar1 = (**(code **)(iVar3 + 0x70))(*(undefined4 *)(iVar3 + 0x74),param_1,puVar5,uVar2);
  }
  if (iVar1 == 0) {
    *param_2 = *param_2 + uVar2;
    memw();
    return 0;
  }
LAB_4012f3f4:
  FUN_4012a73c(param_1,2,0x73);
  return 0xffff9380;
}

