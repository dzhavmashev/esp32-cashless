// Function : FUN_4011ae80
// Address  : 0x4011ae80
// Size     : 47 bytes


void FUN_4011ae80(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_24 [9];
  
  memw();
  auStack_24[0] = param_2;
  iVar1 = (*(code *)&SUB_4008fab8)(*(undefined4 *)*param_1,auStack_24,0xffffffff,0);
  if (iVar1 != 1) {
    (*(code *)&SUB_40094c54)("e mutex",0xfd,"x_fetch"," failed");
  }
  return;
}

