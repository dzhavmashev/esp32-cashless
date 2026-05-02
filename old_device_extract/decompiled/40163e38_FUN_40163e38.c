// Function : FUN_40163e38
// Address  : 0x40163e38
// Size     : 105 bytes


uint FUN_40163e38(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 * 8;
  if (7 < param_1) {
    uVar1 = uVar1 + 0x16;
  }
  if (uVar1 < 0x4000) {
    uVar1 = uVar1 * (int)(&PTR_LAB_3f424558)[param_1 * 2] + 0x3ffff >> 0x12;
  }
  else {
    uVar3 = (uint)(&PTR_LAB_3f424558)[param_1 * 2] & 0x1ff;
    uVar2 = (uint)(&PTR_LAB_3f424558)[param_1 * 2] >> 9 & 0xffff;
    uVar1 = ((int)((uVar3 * (uVar1 >> 9) + (uVar1 & 0x1ff) * uVar2) * 0x200 +
                   uVar3 * (uVar1 & 0x1ff) + 0x3ffff) >> 0x12) + (uVar1 >> 9) * uVar2;
  }
  if (7 < param_1) {
    uVar1 = uVar1 + 3 & 0xfffffffc;
  }
  return uVar1 & 0xffff;
}

