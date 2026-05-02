// Function : FUN_4012f348
// Address  : 0x4012f348
// Size     : 87 bytes


undefined4 FUN_4012f348(int param_1,int *param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  
  puVar4 = (ushort *)*param_2 + 1;
  if (puVar4 <= param_3) {
    uVar1 = *(ushort *)*param_2;
    uVar3 = (uVar1 & 0xff) << 8 | (uint)(uVar1 >> 8);
    *param_2 = (int)puVar4;
    if ((ushort *)((int)puVar4 + uVar3) <= param_3) {
      memw();
      iVar2 = FUN_40134258(*(int *)(param_1 + 0x44) + 0x28,puVar4,uVar3);
      if (iVar2 == 0) {
        *param_2 = *param_2 + uVar3;
        memw();
        return 0;
      }
      return 0xffff8380;
    }
  }
  return 0xffff8400;
}

