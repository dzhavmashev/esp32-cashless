// Function : FUN_400d81dc
// Address  : 0x400d81dc
// Size     : 95 bytes


void FUN_400d81dc(int *param_1)

{
  int iVar1;
  
  FUN_400f0780(0x3ffc5490,"g state");
  do {
    iVar1 = *param_1;
    if (iVar1 == 2) {
      FUN_400d7f78(param_1);
    }
    else if (iVar1 < 3) {
      if (iVar1 == 0) {
        FUN_400d81c0(param_1);
      }
      else if (iVar1 == 1) {
        FUN_400d7e60(param_1);
      }
    }
    else if (iVar1 == 4) {
      FUN_400d8008(param_1);
    }
    else if (iVar1 < 4) {
      FUN_400d803c(param_1);
    }
    else if (iVar1 == 5) {
      FUN_400d813c(param_1);
    }
    FUN_400f1ab4(10);
  } while( true );
}

