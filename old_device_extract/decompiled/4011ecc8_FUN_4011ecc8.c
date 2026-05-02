// Function : FUN_4011ecc8
// Address  : 0x4011ecc8
// Size     : 52 bytes


undefined4 FUN_4011ecc8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x102;
  if (param_1 != 0) {
    if ((DAT_3ffc66e4 == '\0') &&
       (iVar1 = (*(code *)&SUB_4008b33c)(&DAT_3ffc66e4,0x3ffc66e5,5), iVar1 == 0)) {
      return 0x10b;
    }
    (*(code *)&SUB_4008b3d0)(param_1,&DAT_3ffc66e4,6);
    uVar2 = 0;
  }
  return uVar2;
}

