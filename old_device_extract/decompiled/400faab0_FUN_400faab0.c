// Function : FUN_400faab0
// Address  : 0x400faab0
// Size     : 32 bytes


undefined4
FUN_400faab0(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  uVar1 = 0x1107;
  if (*(char *)(param_1 + 0x12) != '\0') {
    uVar1 = FUN_400fa208(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                         param_3,param_4,param_5);
  }
  return uVar1;
}

