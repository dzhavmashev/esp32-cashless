// Function : FUN_40150000
// Address  : 0x40150000
// Size     : 56 bytes


undefined4 FUN_40150000(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = *(undefined1 **)(param_1 + 0xc);
  puVar2 = *(undefined1 **)(param_1 + 0x14);
  if ((puVar3 != (undefined1 *)0x0) && (puVar2 != (undefined1 *)0x0)) {
    puVar1 = (undefined1 *)FUN_4015b1c4();
    *puVar3 = *puVar1;
    memw();
    *puVar2 = puVar1[1];
    memw();
    memw();
    return 0;
  }
  return 0x102;
}

