// Function : FUN_4010c318
// Address  : 0x4010c318
// Size     : 187 bytes


undefined4 FUN_4010c318(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) {
    uVar1 = 0xfa;
  }
  else {
    uVar4 = param_2[5];
    *(char *)(param_1 + 5) = (char)uVar4;
    memw();
    if ((char)uVar4 == '\x06') {
      uVar5 = *param_2;
      *param_1 = uVar5;
      param_1[1] = param_2[1];
      param_1[2] = param_2[2];
      uVar4 = param_2[4];
      param_1[3] = param_2[3];
      *(char *)(param_1 + 4) = (char)uVar4;
      memw();
      if (((char)uVar4 == '\0') &&
         ((((uVar5 & 0xc0ff) == 0x80fe || (((uVar5 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) &&
          (iVar2 = FUN_401172d4(param_1,param_1), iVar2 != 0)))) {
        if (((*param_1 & 0xc0ff) == 0x80fe) ||
           (cVar3 = '\0', ((*param_1 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
          cVar3 = *(char *)(iVar2 + 0xee) + '\x01';
        }
        *(char *)(param_1 + 4) = cVar3;
        memw();
        memw();
      }
    }
    else {
      uVar4 = *param_2;
      param_1[3] = 0;
      *param_1 = uVar4;
      param_1[2] = 0;
      param_1[1] = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      memw();
      memw();
    }
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

