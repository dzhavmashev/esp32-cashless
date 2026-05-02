// Function : FUN_40162dac
// Address  : 0x40162dac
// Size     : 243 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162dac(uint param_1,undefined4 param_2,undefined4 param_3,short param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  uVar3 = param_1 & 0xff;
  uVar4 = 4;
  if (uVar3 < 8) {
    if ((uVar3 == 0) || (uVar3 == 3)) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (2 < uVar3) {
        uVar4 = (uint)(uVar3 < 6);
      }
    }
  }
  iVar5 = uVar4 * 0x24;
  iVar2 = *(int *)(uVar4 * 4 + _DAT_3ffc0034 + 800);
  *(uint *)(*(int *)(iVar2 + 0x2c) + 4) =
       *(uint *)(*(int *)(iVar2 + 0x2c) + 4) & 0xfffffff0 | param_1 & 0xf;
  puVar6 = *(uint **)(iVar2 + 4);
  **(uint **)(iVar2 + 0x2c) = **(uint **)(iVar2 + 0x2c) | 0x80000;
  memw();
  uVar1 = *(ushort *)(iVar2 + 0x16);
  memw();
  *puVar6 = *puVar6 | 0x80000000;
  memw();
  memw();
  *puVar6 = *puVar6 | 0x40000000;
  memw();
  memw();
  *puVar6 = *puVar6 & 0xdfffffff;
  memw();
  puVar6[1] = iVar5 + 0x3ffc1adc;
  memw();
  *puVar6 = *puVar6 & 0xff000fff | (uVar1 & 0xfff) << 0xc;
  *(byte *)(iVar5 + 0x3ffc1add) = *(byte *)(iVar5 + 0x3ffc1add) & 0xf7;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(iVar5 + 0x3ffc1ae0,param_2,6);
  (*(code *)&SUB_4008b3d0)(iVar5 + 0x3ffc1ae6,param_3,6);
  *(ushort *)(iVar5 + 0x3ffc1aec) = (ushort)(uVar3 << 0xc) | 4;
  *(short *)(iVar5 + 0x3ffc1aee) = param_4 << 4;
  memw();
  memw();
  return;
}

