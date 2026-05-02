// Function : FUN_40109d54
// Address  : 0x40109d54
// Size     : 29 bytes


undefined1 FUN_40109d54(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0x4011a9dc;
  if ((*(byte *)(param_2 + 0xeb) & 0x18) == 0) {
    uVar2 = 0x4010af5c;
  }
  uVar1 = FUN_40109d04(param_1,param_2,uVar2);
  return uVar1;
}

