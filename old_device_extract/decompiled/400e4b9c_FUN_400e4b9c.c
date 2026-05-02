// Function : FUN_400e4b9c
// Address  : 0x400e4b9c
// Size     : 58 bytes


void FUN_400e4b9c(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != param_2) {
    param_1[1] = *param_1;
    *param_1 = param_2;
    iVar1 = FUN_400f1a9c();
    param_1[0x7e] = iVar1;
    *(undefined1 *)((int)param_1 + 0x201) = 0;
    *(undefined1 *)((int)param_1 + 0x202) = 0;
    FUN_400f06a4(0x3ffc5490,&DAT_3f407239,param_1[1],param_2);
    if (param_2 - 3U < 3) {
      FUN_400e4af0(param_1);
    }
  }
  return;
}

