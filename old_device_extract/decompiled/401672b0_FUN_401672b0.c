// Function : FUN_401672b0
// Address  : 0x401672b0
// Size     : 297 bytes


undefined4 FUN_401672b0(int *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = *param_1;
  puVar1 = *(uint **)(iVar6 + 0x2c);
  uVar8 = (uint)(byte)puVar1[3];
  if (0xf < (uVar8 - 0x10 & 0xff)) goto LAB_401673d2;
  uVar2 = 0;
  uVar3 = puVar1[4] >> 0x14 & 0xf;
  uVar5 = *puVar1 & 0x400000;
  if ((*(int *)(iVar6 + 0x24) != 0) && ((byte)(*(char *)(*(int *)(iVar6 + 0x24) + 0x82) - 4U) < 2))
  {
    uVar2 = 0x80;
  }
  if (((*puVar1 & 0x4000) != 0) && ((puVar1[4] & 0x40000) != 0)) {
    uVar2 = 0x80;
  }
  uVar4 = (uint)*(ushort *)(iVar6 + 0x16) + (uint)*(ushort *)(iVar6 + 0x14);
  uVar7 = uVar4 & 0xffff;
  if (uVar5 != 0) {
    uVar7 = (uint)*(ushort *)(param_2 + uVar3 * 0x30 + 0x44);
  }
  memw();
  *(uint *)((uint)*(byte *)(param_1 + 1) * -0x3c + 0x3ff74260) =
       uVar2 | uVar8 & 7 | uVar7 << 8 | 0x7000000 | (uint)(uVar5 != 0) << 0x1b |
       (uint)(0x17 < uVar8) << 0x1f;
  if (uVar5 == 0) {
    uVar8 = uVar4 & 0xffff | 0x10000;
LAB_401673b2:
    uVar8 = uVar8 & 0xfff3ffff | 0x40000;
  }
  else {
    param_2 = param_2 + uVar3 * 0x30;
    uVar8 = uVar4 & 0xffff | (*(byte *)(param_2 + 0x40) & 3) << 0x10 |
            (*(byte *)(param_2 + 0x41) & 3) << 0x12;
    if (*(uint *)(param_2 + 0x44) == uVar4) {
      memw();
      goto LAB_401673b2;
    }
  }
  memw();
  *(uint *)((uint)*(byte *)(param_1 + 1) * -0x3c + 0x3ff74264) = uVar8;
LAB_401673d2:
  memw();
  return 0;
}

