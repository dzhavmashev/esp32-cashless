// Function : FUN_4015fab0
// Address  : 0x4015fab0
// Size     : 111 bytes


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_4015fab0(char param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_40;
  undefined2 uStack_3c;
  int aiStack_38 [2];
  char acStack_30 [48];
  
  aiStack_38[1] = 0;
  aiStack_38[0] = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  acStack_30[0] = '\x02';
  memw();
  iVar2 = 4;
  do {
    memw();
    iVar1 = FUN_401663d8(iVar2);
    if (iVar1 == 0) {
      memw();
      FUN_4015fa60(acStack_30,aiStack_38 + 1,aiStack_38,&uStack_40,iVar2,param_3,param_4);
      if (((aiStack_38[0] == 0) && (acStack_30[0] == param_1)) &&
         (iVar1 = (*(code *)&SUB_4008b33c)(&uStack_40,param_2,6), iVar1 == 0)) {
        return 1;
      }
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x19) {
      return 0;
    }
  } while( true );
}

