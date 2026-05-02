// Function : FUN_4014c140
// Address  : 0x4014c140
// Size     : 70 bytes


int FUN_4014c140(int param_1,undefined1 *param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  param_4 = param_4 & 0xff;
  FUN_4014c10c(param_1,0xdd,1,param_4 + 8 & 0xff);
  uVar1 = param_2[1];
  *(undefined1 *)(param_1 + 7) = *param_2;
  memw();
  uVar2 = param_2[2];
  *(undefined1 *)(param_1 + 8) = uVar1;
  *(undefined1 *)(param_1 + 9) = uVar2;
  memw();
  if ((param_4 != 0) && (param_3 != 0)) {
    memw();
    (*(code *)&SUB_4008b3d0)(param_1 + 10,param_3,param_4);
  }
  return param_1 + param_4 + 10;
}

