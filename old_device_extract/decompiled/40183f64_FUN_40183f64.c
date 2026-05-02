// Function : FUN_40183f64
// Address  : 0x40183f64
// Size     : 38 bytes


void FUN_40183f64(uint param_1,uint *param_2)

{
  if (param_2 != (uint *)0x0) {
    *(byte *)(param_2 + 2) = (byte)param_2[2] & 0x80 | 8;
    *param_2 = param_1 & 0xff;
    param_2[1] = 0;
  }
  return;
}

