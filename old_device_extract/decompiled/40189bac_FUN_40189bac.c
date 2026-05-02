// Function : FUN_40189bac
// Address  : 0x40189bac
// Size     : 79 bytes


undefined4 FUN_40189bac(uint param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xff) * -0x3c;
  memw();
  *param_2 = (byte)(*(uint *)(iVar1 + 0x3ff74284) >> 0xc) & 0xf;
  memw();
  memw();
  *(ushort *)(param_2 + 2) = (ushort)*(uint *)(iVar1 + 0x3ff74284) & 0xfff;
  memw();
  memw();
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar1 + 0x3ff74278);
  memw();
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar1 + 0x3ff74274);
  memw();
  return 0;
}

