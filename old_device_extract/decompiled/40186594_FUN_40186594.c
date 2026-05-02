// Function : FUN_40186594
// Address  : 0x40186594
// Size     : 274 bytes


void FUN_40186594(undefined1 *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = 0x87 >> (((int)param_2[3] >> 0x1f) * 8 + 8U & 0x1f);
  uVar4 = uVar3 ^ *param_2 << 1;
  uVar3 = (int)uVar3 >> 0x1f ^ (*param_2 >> 0x1f | uVar1 << 1);
  iVar6 = param_2[3] << 1;
  iVar5 = uVar2 << 1;
  param_1[7] = (char)(uVar3 >> 0x18);
  param_1[6] = (char)(uVar3 >> 0x10);
  param_1[5] = (char)(uVar3 >> 8);
  param_1[3] = (char)(uVar4 >> 0x18);
  param_1[2] = (char)(uVar4 >> 0x10);
  param_1[1] = (char)(uVar4 >> 8);
  param_1[0xf] = (char)((uint)iVar6 >> 0x18);
  param_1[0xe] = (char)((uint)iVar6 >> 0x10);
  param_1[0xd] = (char)((uint)iVar6 >> 8);
  param_1[0xb] = (char)((uint)iVar5 >> 0x18);
  param_1[10] = (char)((uint)iVar5 >> 0x10);
  param_1[4] = (char)uVar3;
  *param_1 = (char)uVar4;
  param_1[0xc] = (byte)(uVar2 >> 0x1f) | (byte)iVar6;
  param_1[9] = (char)((uint)iVar5 >> 8);
  param_1[8] = (byte)(uVar1 >> 0x1f) | (byte)iVar5;
  memw();
  memw();
  return;
}

