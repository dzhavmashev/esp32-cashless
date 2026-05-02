// Function : FUN_401662e4
// Address  : 0x401662e4
// Size     : 244 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401662e4(uint param_1,uint param_2,int param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_2 & 3) != 0) {
    FUN_40147fe4(6,0x2000,2,0x3f43717f);
  }
  uVar3 = (uint)param_4[7] + (uint)param_4[8] * 0x100;
  uVar4 = uVar3 & 0xffff;
  if (param_4[1] == 5) {
    uVar3 = uVar3 & 0xffff | 0x40000;
    uVar4 = 0x10000;
  }
  else {
    uVar3 = (param_4[1] & 7) << 0x12;
  }
  if ((uVar3 & 0x1c0000) == 0x40000) {
    uVar6 = 0xe00000;
  }
  else {
    iVar5 = 3;
    if ((int)param_1 < 4) {
      iVar5 = 6;
    }
    uVar6 = iVar5 << 0x15;
  }
  bVar1 = *param_4;
  bVar2 = param_4[2];
  iVar5 = param_1 * 0x28;
  memw();
  *(uint *)(iVar5 + 0x3ff74400) =
       (uint)param_4[6] * 0x1000000 + (uint)param_4[5] * 0x10000 + (uint)param_4[4] * 0x100 +
       (uint)param_4[3];
  memw();
  *(uint *)(iVar5 + 0x3ff74404) = uVar4 | uVar3 | uVar6 | (bVar1 & 3) << 0x18 | (uint)bVar2 << 0x1e;
  memw();
  _DAT_3ff73814 = 1 << 0x20 - (0x20 - (param_1 & 0x1f)) | _DAT_3ff73814;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(iVar5 + 0x3ff74408,param_2,param_3 + 3U & 0xfffffffc);
  return;
}

