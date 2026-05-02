// Function : FUN_400df194
// Address  : 0x400df194
// Size     : 79 bytes


void FUN_400df194(int param_1,uint param_2)

{
  uint uVar1;
  
  FUN_400f3e98(*(undefined1 *)(param_1 + 0x25),0);
  (*(code *)&SUB_40008534)(0x68);
  uVar1 = 0;
  do {
    FUN_400f3e98(*(undefined1 *)(param_1 + 0x25),(int)(param_2 & 0xffff) >> (uVar1 & 0x1f) & 1);
    uVar1 = uVar1 + 1;
    (*(code *)&SUB_40008534)(0x68);
  } while (uVar1 != 9);
  FUN_400f3e98(*(undefined1 *)(param_1 + 0x25),1);
  (*(code *)&SUB_40008534)(0x68);
  return;
}

