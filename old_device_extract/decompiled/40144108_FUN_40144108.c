// Function : FUN_40144108
// Address  : 0x40144108
// Size     : 90 bytes


int FUN_40144108(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)0x3f4235f8;
  uVar2 = param_2;
  do {
    if (puVar3[1] == 0) {
      if (param_4 != 0) {
        uVar1 = FUN_401742a8(param_1,uVar2,&DAT_3f4231e1,param_3);
        if (((int)uVar1 < 0) || (uVar2 <= uVar1)) {
          return -0x2980;
        }
        uVar2 = uVar2 - uVar1;
      }
      return param_2 - uVar2;
    }
    if ((param_4 & *puVar3) != 0) {
      uVar1 = FUN_401742a8(param_1,uVar2,&DAT_3f4231db,param_3);
      if ((int)uVar1 < 0) {
        return -0x2980;
      }
      if (uVar2 <= uVar1) {
        return -0x2980;
      }
      uVar2 = uVar2 - uVar1;
      param_1 = param_1 + uVar1;
      param_4 = param_4 ^ *puVar3;
    }
    puVar3 = puVar3 + 2;
  } while( true );
}

