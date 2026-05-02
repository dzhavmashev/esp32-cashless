// Function : FUN_400e5614
// Address  : 0x400e5614
// Size     : 58 bytes


void FUN_400e5614(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined1 uStack_31;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  char *pcStack_24;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  FUN_400f06a4(0x3ffc5490,"on: %s\n",param_2);
  uStack_28 = param_3[1];
  uStack_2c = *param_3;
  pcStack_24 = "nd: %s\n";
  uStack_31 = 0;
  uVar1 = FUN_400d49c0(auStack_30,&uStack_31);
  FUN_400e4bd8(param_1,uVar1);
  return;
}

