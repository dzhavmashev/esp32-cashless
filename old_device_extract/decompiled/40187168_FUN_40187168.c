// Function : FUN_40187168
// Address  : 0x40187168
// Size     : 80 bytes


void FUN_40187168(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (param_4 == 2) {
    if ((int)((int)param_1 + param_3 + ((uint)param_1 ^ 0xffffffff)) < 0) {
      param_3 = 1;
    }
    do {
      uVar1 = *(undefined1 *)param_1;
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      *(undefined1 *)param_2 = uVar1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  else {
    param_3 = param_3 >> 2;
    if ((int)(param_3 - 1) < 0) {
      param_3 = 1;
    }
    do {
      uVar2 = *param_1;
      *param_1 = *param_2;
      *param_2 = uVar2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return;
}

