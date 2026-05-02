// Function : FUN_40140e74
// Address  : 0x40140e74
// Size     : 308 bytes


/* WARNING: Removing unreachable block (ram,0x40140ed8) */

void FUN_40140e74(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = param_1 + (*(byte *)(param_2 + 0xf) & 0xf) * 8;
  param_1 = param_1 + (uint)(*(byte *)(param_2 + 0xf) >> 4) * 8;
  uVar3 = *(uint *)(param_1 + 0xb4) ^ *(uint *)(iVar1 + 0xb4) >> 4;
  uVar4 = *(int *)("E (%u) %s: No output supplied\n" + (*(uint *)(iVar1 + 0x30) & 0xf) * 8 + 0x17)
          << 0x10 ^ uVar3;
  uVar6 = *(uint *)(param_1 + 0xb0) ^
          (*(uint *)(iVar1 + 0xb4) << 0x1c | *(uint *)(iVar1 + 0xb0) >> 4);
  uVar2 = *(uint *)(param_1 + 0x30) ^
          (*(uint *)(iVar1 + 0x34) << 0x1c | *(uint *)(iVar1 + 0x30) >> 4);
  uVar5 = *(uint *)(param_1 + 0x34) ^
          (*(uint *)(iVar1 + 0xb0) << 0x1c | *(uint *)(iVar1 + 0x34) >> 4);
  *param_3 = (char)(uVar4 >> 0x18);
  param_3[1] = (char)(uVar4 >> 0x10);
  param_3[2] = (char)(uVar3 >> 8);
  param_3[4] = (char)(uVar6 >> 0x18);
  param_3[5] = (char)(uVar6 >> 0x10);
  param_3[6] = (char)(uVar6 >> 8);
  param_3[8] = (char)(uVar5 >> 0x18);
  param_3[9] = (char)(uVar5 >> 0x10);
  param_3[10] = (char)(uVar5 >> 8);
  param_3[0xc] = (char)(uVar2 >> 0x18);
  param_3[0xd] = (char)(uVar2 >> 0x10);
  param_3[3] = (char)uVar3;
  param_3[7] = (char)uVar6;
  param_3[0xb] = (char)uVar5;
  param_3[0xe] = (char)(uVar2 >> 8);
  param_3[0xf] = (char)uVar2;
  memw();
  memw();
  return;
}

