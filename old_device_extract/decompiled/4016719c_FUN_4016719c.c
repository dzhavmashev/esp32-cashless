// Function : FUN_4016719c
// Address  : 0x4016719c
// Size     : 136 bytes


undefined4 FUN_4016719c(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = *param_1;
  puVar3 = *(uint **)(iVar4 + 0x2c);
  uVar2 = (uint)(byte)puVar3[3];
  uVar1 = uVar2 - 0x10;
  if (0x1f < uVar2) {
    uVar2 = uVar1;
  }
  uVar2 = (uint)((uVar1 & 0xff) < 0x10) << 0x19 | (uint)(byte)puVar3[4] << 0x11 |
          (uVar2 & 0x1f) << 0xc;
  if (((*puVar3 & 0x4000) != 0) && ((puVar3[4] & 0x40000) != 0)) {
    uVar2 = uVar2 | 0x10000000;
  }
  memw();
  *(uint *)((uint)*(byte *)(param_1 + 1) * -0x3c + 0x3ff74258) =
       uVar2 | (uint)*(ushort *)(iVar4 + 0x16) + (uint)*(ushort *)(iVar4 + 0x14) & 0xfff;
  memw();
  return 0;
}

