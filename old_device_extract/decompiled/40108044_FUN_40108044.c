// Function : FUN_40108044
// Address  : 0x40108044
// Size     : 100 bytes


void FUN_40108044(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  uint in_t0;
  
  FUN_4011acdc(param_1 + 5);
  uVar3 = (uint)*(byte *)((int)param_1 + 0xf);
  if (uVar3 == 0) {
    uVar3 = in_t0;
    (*(code *)&SUB_40094c54)("!= NULL",0x25b,"_socket","ng == 0");
  }
  *(char *)((int)param_1 + 0xf) = (char)(uVar3 - 1);
  memw();
  if ((uVar3 - 1 & 0xff) == 0) {
    param_4 = param_1[1];
    param_3 = *param_1;
    param_1[1] = 0;
    *param_1 = 0;
    bVar1 = true;
    memw();
  }
  else {
    uVar2 = 3;
    if (param_2 == 0) {
      uVar2 = 2;
    }
    *(undefined1 *)(param_1 + 4) = uVar2;
    memw();
    bVar1 = false;
  }
  memw();
  FUN_4011ad00(param_1 + 5);
  if (bVar1) {
    FUN_40108020(param_2,param_3,param_4);
  }
  return;
}

