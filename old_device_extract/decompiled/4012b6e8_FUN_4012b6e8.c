// Function : FUN_4012b6e8
// Address  : 0x4012b6e8
// Size     : 7 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012b6e8(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,
                 int param_6,undefined4 param_7,int param_8,undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int in_stack_0000006c;
  uint in_stack_00000094;
  
  do {
    FUN_40138f78(&stack0x00000020);
    if (param_3 != 0) {
      FUN_4013ae54(param_3,param_10);
    }
    FUN_4013ae54(&stack0x0000002c,0x40);
    FUN_4013ae44(param_3);
    param_3 = in_stack_0000006c;
    iVar1 = _DAT_3ffc5708;
    memw();
    memw();
    if (in_stack_0000006c == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
    do {
      iVar2 = FUN_401393f0(iVar1);
      if ((((iVar2 != 0) || (iVar2 = FUN_4013935c(iVar1,param_3,param_5 + param_8), iVar2 != 0)) ||
          (iVar2 = FUN_4013937c(iVar1,&stack0x0000002c), iVar2 != 0)) ||
         (((iVar2 = FUN_401393f0(iVar1), iVar2 != 0 ||
           (iVar2 = FUN_4013935c(iVar1,param_3,param_5), iVar2 != 0)) ||
          (iVar2 = FUN_4013937c(iVar1,param_3), iVar2 != 0)))) break;
      param_4 = param_4 + param_5;
      uVar4 = param_5;
      if (in_stack_00000094 < param_4) {
        uVar4 = in_stack_00000094 % param_5;
      }
      uVar3 = 0;
      while (uVar3 != uVar4) {
        puVar6 = &stack0x0000002c + uVar3;
        puVar5 = (undefined1 *)(param_6 + uVar3);
        uVar3 = uVar3 + 1;
        *puVar5 = *puVar6;
        memw();
        memw();
      }
      param_6 = param_6 + param_5;
    } while (param_4 < in_stack_00000094);
  } while( true );
}

