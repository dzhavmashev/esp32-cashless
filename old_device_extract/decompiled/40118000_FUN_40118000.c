// Function : FUN_40118000
// Address  : 0x40118000
// Size     : 68 bytes


undefined4 FUN_40118000(int param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_4010ba7c(param_1,8);
  uVar2 = 0xfe;
  if (iVar1 == 0) {
    puVar3 = *(undefined1 **)(param_1 + 4);
    puVar3[2] = 5;
    puVar3[3] = 2;
    *puVar3 = param_2;
    puVar3[1] = 0;
    puVar3[4] = param_3;
    puVar3[5] = 0;
    puVar3[6] = 1;
    puVar3[7] = 0;
    memw();
    uVar2 = 0;
  }
  memw();
  return uVar2;
}

