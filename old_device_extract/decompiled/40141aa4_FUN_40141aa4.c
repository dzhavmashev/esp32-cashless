// Function : FUN_40141aa4
// Address  : 0x40141aa4
// Size     : 184 bytes


void FUN_40141aa4(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1 ^ *param_2;
  uVar2 = param_1[1] ^ param_2[1];
  uVar2 = (uint)(byte)(&DAT_3f422c90)[uVar2 >> 8 & 0xff] << 8 |
          (uint)(byte)(&DAT_3f422e90)[uVar2 >> 0x18] << 0x18 |
          (uint)(byte)(&DAT_3f422f90)[uVar2 & 0xff] |
          (uint)(byte)(&DAT_3f422d90)[uVar2 >> 0x10 & 0xff] << 0x10;
  uVar1 = (uint)(CONCAT44(uVar2,uVar2) >> 0x18) ^
          ((uint)(byte)(&DAT_3f422d90)[uVar1 >> 8 & 0xff] << 8 |
          (uint)(byte)(&DAT_3f422f90)[uVar1 >> 0x18] << 0x18 |
          (uint)(byte)(&DAT_3f422c90)[uVar1 & 0xff] |
          (uint)(byte)(&DAT_3f422e90)[uVar1 >> 0x10 & 0xff] << 0x10);
  uVar2 = (uint)(CONCAT44(uVar1,uVar1) >> 0x10) ^ uVar2;
  uVar1 = (uint)(CONCAT44(uVar2,uVar2) >> 8) ^ uVar1;
  *param_3 = uVar2 ^ *param_3 ^ (uint)(CONCAT44(uVar1,uVar1) >> 8);
  param_3[1] = param_3[1] ^ uVar1;
  memw();
  return;
}

