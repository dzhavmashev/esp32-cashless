// Function : FUN_40170aac
// Address  : 0x40170aac
// Size     : 36 bytes


undefined4 FUN_40170aac(byte param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int *in_t0;
  
  uVar1 = (*(code *)&SUB_40094bc8)();
  if (in_t0 != (int *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    in_t0 = (int *)((int)in_t0 + param_2);
    if ((char)param_1 < '\0') {
      in_t0 = (int *)*in_t0;
    }
  }
  *param_4 = (int)in_t0;
  return uVar1;
}

