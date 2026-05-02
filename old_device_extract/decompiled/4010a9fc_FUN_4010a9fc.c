// Function : FUN_4010a9fc
// Address  : 0x4010a9fc
// Size     : 42 bytes


void FUN_4010a9fc(uint param_1,undefined4 *param_2)

{
  if ((param_1 & 0xff) < 3) {
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &DAT_3f411ef4;
    }
    (*(code *)&SUB_4008b3d0)(&DAT_3ffc5cd8 + (param_1 & 0xff) * 0x18,param_2,0x18);
  }
  return;
}

