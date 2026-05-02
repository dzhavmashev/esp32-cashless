// Function : FUN_40138f78
// Address  : 0x40138f78
// Size     : 95 bytes


void FUN_40138f78(int *param_1)

{
  uint uVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      uVar1 = *(uint *)(*param_1 + 4);
      if (uVar1 < 7) {
        if (uVar1 < 5) {
          if (uVar1 == 3) {
            FUN_401416e8();
          }
          else if (uVar1 == 4) {
            FUN_4013ec50();
          }
        }
        else {
          FUN_4013f798();
        }
      }
      else if (uVar1 < 9) {
        FUN_401409a0();
      }
      FUN_4013ae44(param_1[1]);
    }
    if (param_1[2] != 0) {
      FUN_4013ae54(param_1[2],(uint)*(byte *)(*param_1 + 9) << 1);
      FUN_4013ae44(param_1[2]);
    }
    FUN_4013ae54(param_1,0xc);
  }
  return;
}

