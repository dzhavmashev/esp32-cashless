// Function : FUN_400f5c78
// Address  : 0x400f5c78
// Size     : 83 bytes


undefined4 FUN_400f5c78(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(&DAT_3f41450c + (param_1 * 6 + param_3) * 4);
  uVar1 = 0;
  if ((((uVar2 & 0x78000) != 0x78000) && ((uVar2 & 0x7fff) != 0x7fff)) &&
     (uVar3 = (uint)(short)((int)(uVar2 << 0x11) >> 0x11), uVar3 == param_2)) {
    FUN_400f4554(uVar3 & 0xff,(int)(uVar2 << 0xd) >> 0x1c,0);
    uVar1 = 1;
    if ((uVar2 & 0x80000) != 0) {
      FUN_400f44f0(uVar3,uVar2 >> 0x14);
      uVar1 = 1;
    }
  }
  return uVar1;
}

