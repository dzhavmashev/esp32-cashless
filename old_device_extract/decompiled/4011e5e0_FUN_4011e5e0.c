// Function : FUN_4011e5e0
// Address  : 0x4011e5e0
// Size     : 159 bytes


ushort FUN_4011e5e0(uint *param_1,uint param_2,uint param_3,int param_4)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *param_1 >> 0x11 & 0x1f;
  iVar4 = FUN_40123800(uVar5,param_3);
  uVar3 = 0;
  if ((iVar4 != 1) && (param_4 != -1 || iVar4 != 2)) {
    bVar2 = FUN_401237ec(uVar5);
    uVar3 = 0;
    if ((param_2 & 1 << (bVar2 & 0x1f)) != 0) {
      iVar4 = FUN_401237d8(uVar5);
      if ((param_2 & 0x200) == 0) {
        if (iVar4 == 1) {
          return 0;
        }
      }
      else if (iVar4 == 0) {
        return 0;
      }
      uVar1 = (ushort)*param_1;
      if ((uVar1 & 1) == 0) {
        if ((uVar1 & 0xc) == 0xc) {
          (*(code *)&SUB_40094c54)("support/intr_alloc.c",0xfb,"tr_free","_random");
        }
        if ((uVar1 & 8) == 0) {
          if ((uVar1 & 4) == 0) {
            uVar3 = FUN_4011f6a8(uVar5,param_3 & 0xff);
            uVar3 = (uVar3 ^ 1) & 0xff;
          }
          else if (((param_2 & 0x100) != 0) && (uVar3 = 1, (param_2 >> 10 & 1) != (uVar1 >> 1 & 1)))
          {
            uVar3 = uVar1 & 8;
          }
        }
      }
    }
  }
  return uVar3;
}

