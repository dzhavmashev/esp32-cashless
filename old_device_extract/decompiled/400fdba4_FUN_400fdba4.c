// Function : FUN_400fdba4
// Address  : 0x400fdba4
// Size     : 82 bytes


void FUN_400fdba4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(uint *)(param_1 + 4) & 0xfffffffc);
  if (puVar1 + -0x10000001 < (undefined4 *)0x400000) {
    FUN_400fd498("\r\n");
    FUN_400fd4c0(puVar1 + -1);
    FUN_400fd498("(%04X)");
    memw();
    FUN_400fd4c0(puVar1[-1]);
    FUN_400fd498(" Type");
    memw();
    FUN_400fd4c0(*puVar1);
    FUN_400fd498(" Type");
    memw();
    FUN_400fd4c0(puVar1[1]);
  }
  return;
}

