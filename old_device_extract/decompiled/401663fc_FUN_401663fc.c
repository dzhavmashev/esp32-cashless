// Function : FUN_401663fc
// Address  : 0x401663fc
// Size     : 151 bytes


void FUN_401663fc(int param_1,uint param_2,int param_3,byte *param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_2 & 3) != 0) {
    FUN_40147fe4(6,0x2000,2,0x3f437176);
  }
  param_1 = param_1 * 0x28;
  uVar3 = *(undefined4 *)(param_1 + 0x3ff74400);
  uVar2 = *(uint *)(param_1 + 0x3ff74404);
  param_4[3] = (byte)uVar3;
  param_4[6] = (byte)((uint)uVar3 >> 0x18);
  param_4[8] = (byte)(uVar2 >> 8);
  bVar1 = (byte)(uVar2 >> 0x18);
  *param_4 = bVar1 & 3;
  param_4[2] = bVar1 >> 6;
  memw();
  param_4[7] = (byte)uVar2;
  bVar1 = (byte)(uVar2 >> 0x12) & 7;
  param_4[4] = (byte)((uint)uVar3 >> 8);
  param_4[5] = (byte)((uint)uVar3 >> 0x10);
  memw();
  if ((uVar2 & 0x1f0000) == 0x50000) {
    bVar1 = 5;
    memw();
  }
  param_4[1] = bVar1;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(param_2,param_1 + 0x3ff74408,param_3 + 3U & 0xfffffffc);
  return;
}

