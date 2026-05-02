// Function : FUN_401720d0
// Address  : 0x401720d0
// Size     : 22 bytes


void FUN_401720d0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)&SUB_40001778)(*puVar1);
    FUN_4016fa50(puVar1);
  }
  return;
}

