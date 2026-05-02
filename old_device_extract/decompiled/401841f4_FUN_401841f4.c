// Function : FUN_401841f4
// Address  : 0x401841f4
// Size     : 37 bytes


void FUN_401841f4(uint param_1,uint *param_2)

{
  if (param_2 != (uint *)0x0) {
    *(byte *)(param_2 + 2) = (byte)param_2[2] & 0x80 | 8;
    *param_2 = param_1 & 0xffff;
    param_2[1] = 0;
  }
  return;
}

