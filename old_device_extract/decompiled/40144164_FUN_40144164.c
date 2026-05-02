// Function : FUN_40144164
// Address  : 0x40144164
// Size     : 56 bytes


undefined4 FUN_40144164(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 0x118) & 4) != 0) {
    uVar1 = 0xffffd800;
    if (((param_2 & 0xffff7ffe) == (param_2 & 0xffff7ffe & *(uint *)(param_1 + 0x124))) &&
       (uVar1 = 0, (param_2 & 0x8001) != ((param_2 | *(uint *)(param_1 + 0x124)) & 0x8001))) {
      uVar1 = 0xffffd800;
    }
  }
  return uVar1;
}

